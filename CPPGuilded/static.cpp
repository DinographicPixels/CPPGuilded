//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include <static.hpp>

#include <boost/certify/https_verification.hpp>

void load_ssl_certificates(boost::asio::ssl::context& ssl_context) {
#if defined(_WIN32) //|| defined(__APPLE__)
    boost::certify::enable_native_https_server_verification(ssl_context);
#else
    ssl_context.set_default_verify_paths();
#endif
}
