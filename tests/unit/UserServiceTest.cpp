#include <gtest/gtest.h>
#include "../../src/core/UserService.h"
#include "../../src/interfaces/IUserRepository.h"
#include "../../src/models/User.h"
#include <vector>

class MockUserRepository : public IUserRepository {
public:
    std::vector<User> savedUsers;

    std::optional<User> findById(int id) override {
        for (auto& u : savedUsers)
            if (u.id == id) return u;
        return std::nullopt;
    }

    void save(const User& user) override {
        savedUsers.push_back(user);
    }
};

TEST(UserServiceTest, RegisterUserSavesCorrectly) {
    auto repo = std::make_shared<MockUserRepository>();
    UserService service(repo);
    service.registerUser("Alice", "alice@example.com");

    ASSERT_EQ(repo->savedUsers.size(), 1);
    EXPECT_EQ(repo->savedUsers[0].name, "Alice");
}
