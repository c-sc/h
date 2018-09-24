#include <eosiolib/eosio.hpp>
#include "blank.hpp"

using namespace eosio;

namespace blankspace{
    struct impl{

        void hello(const account_name& user){
            blank::complex test(1,2);
            print(" complex ", (int) test.re, " + ", (int) test.im, "i");
        }

        void on(const blank::hi& h) {
            print( " Hello: ", name{h.user} );
        }

        void on( const blank::nroom& nroom){
            print( " Host: ", name{nroom.host} );
            require_auth(nroom.host);
            blank::room _room(nroom.host,nroom.guests);
            blank::rooms existing_host_rooms(code_account, _room.host);
            auto itr = existing_host_rooms.find( _room.id );
            eosio_assert(itr == existing_host_rooms.end(), "Room already exists");
            existing_host_rooms.emplace(_room.host, [&]( auto& nr ) {
                nr = _room;
            });
        }

        void on(const blank::npost& _npost) {
            print( " By: ", name{_npost.by} );
            require_auth(_npost.by);
            blank::room _room(_npost.host,_npost.guests);
            blank::rooms existing_host_rooms( code_account,_room.host );
            auto itr = existing_host_rooms.find( _room.id );
            eosio_assert(itr != existing_host_rooms.end(), "Room dosen't exists");
            blank::posts existing_room_posts(code_account, _npost.host);
            uint64_t _id = existing_room_posts.available_primary_key();
            print("post id: ", _id);
            blank::post _post(_id,_npost.by,_npost.host,_npost.guests,_npost.message);
            existing_room_posts.emplace(_npost.by, [&]( auto& p ){
                p = _post;
            });
        }

        void apply( uint64_t /*receiver*/, uint64_t code, uint64_t action ) {
            if (code == code_account) {
                if (action == N(hi)) {
                impl::on(eosio::unpack_action_data<blank::hi>());
                } else if (action == N(nroom)) {
                impl::on(eosio::unpack_action_data<blank::nroom>());
                } else if (action == N(npost)) {
                impl::on(eosio::unpack_action_data<blank::npost>());
                } else if (action == N(hello)) {
                hello(eosio::unpack_action_data<account_name>());
                }
            }
        }
    };
};
extern "C" {
    using namespace blankspace;
    void apply( uint64_t receiver, uint64_t code, uint64_t action ) {
        impl().apply(receiver, code, action);
    }
}