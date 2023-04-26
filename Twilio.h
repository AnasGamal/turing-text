#ifndef TWILIO_H
#define TWILIO_H

#include <iostream>
#include <string>
#include <memory>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <curl/curl.h>

using boost::asio::ip::tcp;
using boost::placeholders::_1;

class TwilioServer {
	public:
	TwilioServer(boost::asio::io_context& io_context, short port);

	private:
	void start_accept();
	void handle_request(std::shared_ptr<tcp::socket> socket, const boost::system::error_code& error);
	tcp::acceptor acceptor_;
};

class TwilioClient {
	public:
	TwilioClient(const std::string& account_sid, const std::string& auth_token, const std::string& from_number);
	void send_sms(const std::string& to_number, const std::string& message);

	private:
	std::string account_sid_;
	std::string auth_token_;
	std::string from_number_;
};

void start_twilio();

#endif // TWILIO_H
