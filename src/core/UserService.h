#pragma once
#include <memory>
#include "../models/User.h"
#include "../interfaces/IUserRepository.h"

class UserService {
    std::shared_ptr<IUserRepository> repo;
public:
    UserService(std::shared_ptr<IUserRepository> repo) : repo(repo) {}
    void registerUser(const std::string& name, const std::string& email) {
        User user{-1, name, email};
        repo->save(user);
    }
    std::optional<User> getUser(int id) {
        return repo->findById(id);
    }
};
