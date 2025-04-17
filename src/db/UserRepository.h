#pragma once
#include "../interfaces/IUserRepository.h"
#include <sqlite3.h>
#include <iostream>

class UserRepository : public IUserRepository {
    sqlite3* db;

public:
    UserRepository() {
        sqlite3_open("users.db", &db);
        char* errMsg = nullptr;
        sqlite3_exec(db,
            "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT);",
            nullptr, nullptr, &errMsg);
    }

    ~UserRepository() {
        sqlite3_close(db);
    }

    std::optional<User> findById(int id) override {
        sqlite3_stmt* stmt;
        User user;
        if (sqlite3_prepare_v2(db, "SELECT name, email FROM users WHERE id = ?;", -1, &stmt, nullptr) == SQLITE_OK) {
            sqlite3_bind_int(stmt, 1, id);
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                user.id = id;
                user.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                user.email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                sqlite3_finalize(stmt);
                return user;
            }
        }
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    void save(const User& user) override {
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, "INSERT INTO users (name, email) VALUES (?, ?);", -1, &stmt, nullptr) == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, user.name.c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, user.email.c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
    }
};
