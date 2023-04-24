#include <iostream>
#include <string>
#include <memory>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <curl/curl.h>

using boost::asio::ip::tcp;
using boost::placeholders::_1;

class TwilioServer
{
	public:
		TwilioServer(boost::asio::io_context &io_context, short port)
			: acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
		{
			start_accept();
		}

	private:
		void start_accept()
		{
			auto socket = std::make_shared<tcp::socket>(acceptor_.get_executor());
			acceptor_.async_accept(*socket, boost::bind(&TwilioServer::handle_request, this, socket, _1));
		}

		void handle_request(std::shared_ptr<tcp::socket> socket, const boost::system::error_code &error)
		{
			if (!error)
			{
				boost::asio::streambuf request_buf;
				boost::asio::read_until(*socket, request_buf, "\r\n\r\n");
				std::string request_data(boost::asio::buffers_begin(request_buf.data()), boost::asio::buffers_end(request_buf.data()));

				// Find the end of the headers
				size_t header_end = request_data.find("\r\n\r\n");
				if (header_end == std::string::npos)
				{
					std::cerr << "Error: Could not find end of headers" << std::endl;
					return;
				}

				// Parse the request parameters
				std::string params_data = request_data.substr(request_data.find('?') + 1, header_end - request_data.find('?') - 1);
				std::istringstream params_stream(params_data);

				boost::property_tree::ptree params_ptree;
				std::string param_name, param_value;
				while (std::getline(params_stream, param_name, '=') && std::getline(params_stream, param_value, '&'))
				{
					params_ptree.put(param_name, param_value);
				}

				// Create a JSON object containing the request parameters
				boost::property_tree::ptree request_ptree;
				request_ptree.put_child("Body", params_ptree);

				// Write the JSON object to the console
				std::ostringstream request_ostream;
				boost::property_tree::write_json(request_ostream, request_ptree);
				std::string request_json = request_ostream.str();
				std::cout << "Received request JSON: " << request_json << std::endl;

				std::string response_body = request_ptree.get<std::string>("Body.Body");

				if (response_body == "yes")
				{
					std::string response_body ="Let's Get Ready to Rumble";

					std::ostringstream response_stream;
					response_stream << "HTTP/1.1 200 OK\r\n";
					response_stream << "Content-Type: text/plain\r\n";
					response_stream << "Content-Length: " << response_body.length() << "\r\n\r\n";
					response_stream << response_body;
					std::string response = response_stream.str();
					boost::asio::write(*socket, boost::asio::buffer(response));
				}

				// Send the response
				// std::string response_body = request_ptree.get<std::string>("Body.ToCountry");

				// std::ostringstream response_stream;
				// response_stream << "HTTP/1.1 200 OK\r\n";
				// response_stream << "Content-Type: text/plain\r\n";
				// response_stream << "Content-Length: " << response_body.length() << "\r\n\r\n";
				// response_stream << response_body;
				// std::string response = response_stream.str();
				// boost::asio::write(*socket, boost::asio::buffer(response));
			}

			start_accept();
		}

		tcp::acceptor acceptor_;
};

class TwilioClient
{
	public:
		TwilioClient(const std::string &account_sid, const std::string &auth_token, const std::string &from_number)
			: account_sid_(account_sid), auth_token_(auth_token), from_number_(from_number) {}

		void send_sms(const std::string &to_number, const std::string &message)
		{
			CURL *curl = curl_easy_init();
			if (curl)
			{
				// Set Twilio API endpoint
				std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + account_sid_ + "/Messages.json";
				curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

				// Set authentication
				std::string credentials = account_sid_ + ":" + auth_token_;
				curl_easy_setopt(curl, CURLOPT_USERPWD, credentials.c_str());

				// Set message parameters
				std::string data = "From=" + from_number_ + "&To=" + to_number + "&Body=" + message;

				// Set POST data
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

				// Perform request
				CURLcode res = curl_easy_perform(curl);
				if (res != CURLE_OK)
				{
					std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
				}

				// Clean up
				curl_easy_cleanup(curl);
			}
		}

	private:
		std::string account_sid_;
		std::string auth_token_;
		std::string from_number_;
};

int main()
{
	std::string account_sid = "accountSID";
	std::string auth_token = "authtoken";
	std::string from_number = "twilio#";
	TwilioClient client(account_sid, auth_token, from_number);

	std::string to_number = "your number";
	std::string message = "Welcome to Turing Text! Do you want to play the game?";
	client.send_sms(to_number, message);

	try
	{
		boost::asio::io_context io_context;
		TwilioServer server(io_context, 8080);
		io_context.run();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
