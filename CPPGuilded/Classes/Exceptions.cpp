#include "Exceptions.hpp"

CPPGuilded::GuildedException::GuildedException(const std::string& what) {
    _what = what;
}

CPPGuilded::GuildedException::~GuildedException() {
}

const char* CPPGuilded::GuildedException::what() const noexcept {
    return _what.c_str();
}

CPPGuilded::StatusCodeException::StatusCodeException(const std::string& what, int error_code) : GuildedException(what) {
    _error_code = error_code;
}

CPPGuilded::StatusCodeException::~StatusCodeException() {
}

///@return	error code of this exception
int CPPGuilded::StatusCodeException::get_error_code() const {
    return _error_code;
}

CPPGuilded::ClientException::ClientException(const std::string& what) : GuildedException(what) {
}

CPPGuilded::SizeError::SizeError(const std::string& what) : GuildedException(what) {
}

CPPGuilded::OpusError::OpusError(const std::string& what, int error_code) : StatusCodeException(what, error_code) {
}

CPPGuilded::HTTPError::HTTPError(const std::string& what, int error_code) : StatusCodeException(what, error_code) {
}