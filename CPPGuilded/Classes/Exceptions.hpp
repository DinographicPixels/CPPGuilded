#pragma once
#include <exception>
#include <iostream>

#ifndef CPPGUILDED_EXCEPTIONS_HPP
#define CPPGUILDED_EXCEPTIONS_HPP

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

namespace CPPGuilded {
    class GuildedException : public std::exception {
    protected:
        std::string _what;

    public:
        DLL_EXPORT GuildedException(const std::string& what);
        DLL_EXPORT virtual ~GuildedException();

        DLL_EXPORT const char* what() const noexcept;
    };

    class StatusCodeException : public GuildedException {
    protected:
        int _errorCode;

    public:
        DLL_EXPORT StatusCodeException(const std::string& what, int errorCode);
        DLL_EXPORT virtual ~StatusCodeException();
        DLL_EXPORT int get_error_code() const;
    };

    class ClientException : public GuildedException {
    public:
        DLL_EXPORT ClientException(const std::string& what);
    };

    class SizeError : public GuildedException {
    public:
        DLL_EXPORT SizeError(const std::string& what);
    };

    class OpusError : public StatusCodeException {
    public:
        DLL_EXPORT OpusError(const std::string& what, int errorCode);
    };

    class HTTPError : public StatusCodeException {
    public:
        DLL_EXPORT HTTPError(const std::string& what, int errorCode);
    };
}

#endif
