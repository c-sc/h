#include <eosiolib/eosio.hpp>
#include <eosiolib/crypto.h>

using std::string;
using std::vector;
using std::sort;

static const account_name code_account = N(blankacccode);

class blank : public eosio::contract {
    public:
        blank( account_name self ):contract(self){}
      
        struct complex {
            uint8_t re;
            uint8_t im;
            complex(uint8_t _re, uint8_t _im): re(_re),im(_im){}
            EOSLIB_SERIALIZE( complex, (re)(im) )
        };

        /// @abi table rooms i64
        struct room {
            uint64_t id;
            time created;
            account_name host;
            vector<account_name> guests;

            room(){}

            room(account_name _host, vector<account_name> _guests):host(_host),guests(_guests),created(now()){
                string name("");
                checksum160 calc_hash;

                sort(guests.begin(),guests.end());

                name.append(eosio::name{host}.to_string());
                for( uint8_t i = 0; i < guests.size(); i++){
                    name.append(","+eosio::name{guests[i]}.to_string());
                }

                char *namechar = new char[name.length()];
                strcpy(namechar, name.c_str());
                ripemd160( namechar, name.length(), &calc_hash );

                id = ((uint64_t) calc_hash.hash[0] << 8*7)+
                    ((uint64_t) calc_hash.hash[1] << 8*6)+
                    ((uint64_t) calc_hash.hash[2] << 8*5)+
                    ((uint64_t) calc_hash.hash[3] << 8*4)+
                    ((uint32_t) calc_hash.hash[4] << 8*3)+
                    ((uint32_t) calc_hash.hash[5] << 8*2)+
                    ((uint16_t) calc_hash.hash[6] << 8)+
                    calc_hash.hash[7];
            }
            
            auto primary_key() const { return id; }

            EOSLIB_SERIALIZE( room, (id)(created)(host)(guests) )
        };
      
        typedef eosio::multi_index< N(rooms), room> rooms;

        /// @abi table posts i64
        struct post {
            uint64_t id;
            uint64_t roomid;
            time created;
            account_name author;
            string message = "";

            post(){}

            post(uint64_t _id, account_name _author, account_name _host, vector<account_name> _guests, string _message)
                :id(_id),author(_author),created(now()){
                    message = _message;
                    room _room(_host,_guests);
                    roomid = _room.id;
                }
            auto primary_key() const { return id; }

            EOSLIB_SERIALIZE( post, (id)(roomid)(created)(author)(message) )
        };

        typedef eosio::multi_index< N(posts), post> posts;

        /// @abi action
        void hello(const account_name& user);

        /// @abi action 
        struct hi{
            account_name user;
            EOSLIB_SERIALIZE( hi, (user) )
        };

        /// @abi action
        struct nroom {
            account_name host;
            vector<account_name> guests;
            EOSLIB_SERIALIZE( nroom, (host)(guests) )
        };
        
        /// @abi action
        struct npost {
            account_name host;
            vector<account_name> guests;
            account_name by;
            string message;
            EOSLIB_SERIALIZE( npost, (host)(guests)(by)(message) )
        };
};