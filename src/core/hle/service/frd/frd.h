// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include "common/common_types.h"
#include "core/hle/service/service.h"

namespace Core {
class System;
}

namespace Kernel {
class Event;
}

namespace Service::FRD {

struct FriendKey {
    u32 friend_id;
    u32 unknown;
    u64 friend_code;

private:
    template <class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar & friend_id;
        ar & unknown;
        ar & friend_code;
    }
    friend class boost::serialization::access;
};

struct MyPresence {
    u32 join_flag;
    u32 matchmake_type;
    u32 join_game_id;
    u32 join_game_mode;
    u32 owner_id;
    u32 join_group_id;
    u8  app_arg[20];

private:
    template <class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar & join_flag;
        ar & matchmake_type;
        ar & join_game_id;
        ar & join_game_mode;
        ar & owner_id;
        ar & join_group_id;
        ar & app_arg;
    }
    friend class boost::serialization::access;
};

struct FriendAccount {
    std::array<u16_le, 0x10> nex_password{};

private:
    template <class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar & nex_password;
    }
    friend class boost::serialization::access;
};

struct GameAuthenticationData {
    u32 nasc_result;
    u32 http_status_code;
    std::array<char, 32> server_address{};
    u16 server_port;
    INSERT_PADDING_BYTES(0x6);
    std::array<char, 256> auth_token{};
    u64 server_time;

    void Init() {
        memset(this, 0, sizeof(*this));
    }

private:
    template <class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar& nasc_result;
        ar& http_status_code;
        ar& server_address;
        ar& server_port;
        ar& auth_token;
        ar& server_time;
    }
    friend class boost::serialization::access;
};

struct Profile {
    u8 region;
    u8 country;
    u8 area;
    u8 language;
    u8 platform;
    INSERT_PADDING_BYTES(0x3);
};
static_assert(sizeof(Profile) == 0x8, "Profile has incorrect size");

struct Game {
    u64 title_id;
    u16 version;
    INSERT_PADDING_BYTES(0x6);
};
static_assert(sizeof(Game) == 0x10, "Game has inccorect size");

struct ScreenName {
    // 20 bytes according to 3dbrew
    std::array<char16_t, 10> name;
};
static_assert(sizeof(ScreenName) == 0x14, "ScreenName has inccorect size");

struct Comment {
    // 32 bytes according to 3dbrew
    std::array<char16_t, 16> name;
};
static_assert(sizeof(Comment) == 0x20, "Comment has inccorect size");

class Module final {
public:
    explicit Module(Core::System& system);
    ~Module();

    class Interface : public ServiceFramework<Interface> {
    public:
        Interface(std::shared_ptr<Module> frd, const char* name, u32 max_session);
        ~Interface();

    protected:
        /**
         * FRD::GetMyPresence service function
         *  Inputs:
         *      64 : sizeof (MyPresence) << 14 | 2
         *      65 : Address of MyPresence structure
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void GetMyPresence(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetFriendKeyList service function
         *  Inputs:
         *      1 : Unknown
         *      2 : Max friends count
         *      65 : Address of FriendKey List
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2 : FriendKey count filled
         */
        void GetFriendKeyList(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetFriendProfile service function
         *  Inputs:
         *      1 : Friends count
         *      2 : Friends count << 18 | 2
         *      3 : Address of FriendKey List
         *      64 : (count * sizeof (Profile)) << 10 | 2
         *      65 : Address of Profiles List
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void GetFriendProfile(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetFriendAttributeFlags service function
         *  Inputs:
         *      1 : Friends count
         *      2 : Friends count << 18 | 2
         *      3 : Address of FriendKey List
         *      65 : Address of AttributeFlags
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void GetFriendAttributeFlags(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyFriendKey service function
         *  Inputs:
         *      none
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2-5 : FriendKey
         */
        void GetMyFriendKey(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyScreenName service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2 : UTF16 encoded name (max 11 symbols)
         */
        void GetMyScreenName(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyMii service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2 : MiiStoreData structure
         */
        void GetMyMii(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyProfile service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *    2-3 : Profile structure
         */
        void GetMyProfile(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyComment service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2 : UTF16 encoded comment (max 16 symbols)
         */
        void GetMyComment(Kernel::HLERequestContext& ctx);
        
        void GetMyPassword(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyFavoriteGame service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *    2-3 : Game structure
         */
        void GetMyFavoriteGame(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyPlayingGame service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *    2-3 : Game structure
         */
        void GetMyPlayingGame(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetMyPreference service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2 : Public mode (byte, 0 = private, non-zero = public)
         *      3 : Show current game (byte, 0 = don't show, non-zero = show)
         *      4 : Show game history (byte, 0 = don't show, non-zero = show)
         */
        void GetMyPreference(Kernel::HLERequestContext& ctx);

        /**
         * FRD::UnscrambleLocalFriendCode service function
         *  Inputs:
         *      1 : Friend code count
         *      2 : ((count * 12) << 14) | 0x402
         *      3 : Pointer to encoded friend codes. Each is 12 bytes large
         *      64 : ((count * 8) << 14) | 2
         *      65 : Pointer to write decoded local friend codes to. Each is 8 bytes large.
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void UnscrambleLocalFriendCode(Kernel::HLERequestContext& ctx);

        void UpdateGameModeDescription(Kernel::HLERequestContext& ctx);

        void AttachToEventNotification(Kernel::HLERequestContext& ctx);

        void SetNotificationMask(Kernel::HLERequestContext& ctx);

        void GetGameAuthenticationData(Kernel::HLERequestContext& ctx);

        /**
         * FRD::SetClientSdkVersion service function
         *  Inputs:
         *      1 : Used SDK Version
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void SetClientSdkVersion(Kernel::HLERequestContext& ctx);

        /**
         * FRD::Login service function
         *  Inputs:
         *      65 : Address of unknown event
         *  Outputs:
         *      1  : Result of function, 0 on success, otherwise error code
         */
        void Login(Kernel::HLERequestContext& ctx);
        
        void Logout(Kernel::HLERequestContext& ctx);

        /**
         * FRD::IsOnline service function
         *  Inputs:
         *      none
         *  Outputs:
         *      1  : Result of function, 0 on success, otherwise error code
         *      2  : Online state (8-bit, 0 = not online, non-zero = online)
         */
        void IsOnline(Kernel::HLERequestContext& ctx);

        /**
         * FRD::HasLoggedIn service function
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2 : If the user has logged in 1, otherwise 0
         */
        void HasLoggedIn(Kernel::HLERequestContext& ctx);

        /**
         * FRD::GetLastResponseResult service function
         *  Inputs:
         *      none
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void GetLastResponseResult(Kernel::HLERequestContext& ctx);

    protected:
        std::shared_ptr<Module> frd;
    };

private:
    FriendAccount friend_account;
    GameAuthenticationData game_authentication_data;
    FriendKey my_friend_key = {0, 0, 0ull};
    MyPresence my_presence = {};
    bool logged_in = false;
    std::shared_ptr<Kernel::Event> login_event;
    Core::TimingEventType* login_delay_event;
    Core::System& system;
    
    u32 notif_event_mask = 0xF7;
    std::shared_ptr<Kernel::Event> notif_event;

    template <class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar & friend_account;
        ar & game_authentication_data;
        ar & my_friend_key;
        ar & my_presence;
        ar & logged_in;
    }
    friend class boost::serialization::access;
};

void InstallInterfaces(Core::System& system);

} // namespace Service::FRD

SERVICE_CONSTRUCT(Service::FRD::Module)
