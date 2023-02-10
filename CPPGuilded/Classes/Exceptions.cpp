#include "Exceptions.hpp"

CPPGuilded::GuildedException::GuildedException(const std::string& what) {
    _what = what;
}

CPPGuilded::GuildedException::~GuildedException() {
}

const char* CPPGuilded::GuildedException::what() const noexcept {
    return _what.c_str();
}

CPPGuilded::StatusCodeException::StatusCodeException(const std::string& what, int errorCode) : GuildedException(what) {
    _errorCode = errorCode;
}

CPPGuilded::StatusCodeException::~StatusCodeException() {
}

///@return	error code of this exception
int CPPGuilded::StatusCodeException::get_error_code() const {
    return _errorCode;
}

CPPGuilded::ClientException::ClientException(const std::string& what) : GuildedException(what) {
}

CPPGuilded::SizeError::SizeError(const std::string& what) : GuildedException(what) {
}

CPPGuilded::OpusError::OpusError(const std::string& what, int errorCode) : StatusCodeException(what, errorCode) {
}

CPPGuilded::HTTPError::HTTPError(const std::string& what, int errorCode) : StatusCodeException(what, errorCode) {
}