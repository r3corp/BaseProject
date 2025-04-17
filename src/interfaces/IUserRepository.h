#pragma once
#include <optional>
#include "../models/User.h"

class IUserRepository {
public:
    virtual std::optional<User> findById(int id) = 0;
    virtual void save(const User& user) = 0;
    virtual ~IUserRepository() = default;
};
