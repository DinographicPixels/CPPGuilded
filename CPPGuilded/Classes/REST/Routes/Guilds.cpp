//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Guilds.hpp"
#include <iostream>
#include "static.hpp"

#include "Classes/Member.hpp"
#include "Classes/RequestHandler.hpp"
#include "Classes/Guild.hpp"
#include "Classes/BannedMember.hpp"

CPPGuilded::Guilds::Guilds(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager): client(client), manager(std::move(manager)) {};

CPPGuilded::Member CPPGuilded::Guilds::get_member(const std::string& guildID, const std::string& memberID) {
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID + "/members/" + memberID);
	json res = json::parse(req.body).at("member");
	return Member{res, client};
}

vector<CPPGuilded::Member> CPPGuilded::Guilds::get_members(const std::string& guildID)
{
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID + "/members");
	json res = json::parse(req.body).at("members");
	vector<CPPGuilded::Member> members;
	for (const json& member : res){
		members.emplace_back(Member(member, client));
	}
	return members;
}

CPPGuilded::Guild CPPGuilded::Guilds::get_guild(const std::string& guildID)
{
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID);
	json res = json::parse(req.body).at("server");
	return Guild{res, client};
}

std::string CPPGuilded::Guilds::change_member_nickname(const std::string& guildID, const std::string& memberID, const std::string& nickname)
{
	RequestHandler::GuildedHTTPResponse req = manager->request("PUT", "/servers/" + guildID + "/members/" + memberID + "/nickname", json{{"nickname", nickname}});
	json res = json::parse(req.body).at("nickname");
	return res;
}

void CPPGuilded::Guilds::delete_member_nickname(const std::string& guildID, const std::string& memberID)
{
	manager->request("DELETE", "/servers/" + guildID + "/members/" + memberID + "/nickname");
}

void CPPGuilded::Guilds::remove_member(const std::string& guildID, const std::string& memberID)
{
	manager->request("DELETE", "/servers/" + guildID + "/membes/" + memberID);
}

CPPGuilded::BannedMember CPPGuilded::Guilds::create_ban(const std::string& guildID, const std::string& memberID, const std::optional<std::string>& reason)
{
	RequestHandler::GuildedHTTPResponse req;
	if (reason) {
		req = manager->request("POST", "/servers/" + guildID + "/bans/" + memberID, json{{"reason", reason.value()}});
	} else {
		req = manager->request("POST", "/servers/" + guildID + "/bans/" + memberID);
	}
	json res = json::parse(req.body).at("serverMemberBan");
	return BannedMember{guildID, res, client};
}

void CPPGuilded::Guilds::remove_ban(const std::string& guildID, const std::string& memberID)
{
	manager->request("DELETE", "/servers/" + guildID + "/bans/" + memberID);
}

CPPGuilded::BannedMember CPPGuilded::Guilds::get_ban(const std::string& guildID, const std::string& memberID)
{
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID + "/bans/" + memberID);
	json res = json::parse(req.body).at("serverMemberBan");
	return BannedMember{guildID, res, client};
}

vector<CPPGuilded::BannedMember> CPPGuilded::Guilds::get_bans(const std::string& guildID)
{
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID + "/bans");
	json res = json::parse(req.body).at("serverMemberBans");
	vector<CPPGuilded::BannedMember> bans;
	for (const json& ban : res){
		bans.emplace_back(BannedMember(guildID, ban, client));
	}
	return bans;
}