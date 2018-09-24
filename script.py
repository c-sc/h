import node
import eosf
import sess

# Start node
node.reset()
sess.boot()

messengerio = eosf.account(
    sess.eosio,
    name="blankacccode",
    stake_net="100 SYS",
    stake_cpu="100 SYS",
    buy_ram_kbytes="5000",
    permission="eosio",
    transfer=True
)


# Import to local wallet
sess.wallet.import_key(messengerio)
 
messenger = eosf.Contract(messengerio, "h")
#messenger.build()
messenger.deploy()


# Create game

messenger.push_action("hi", '["world"]')
messenger.push_action("hello", '["world"]')

messenger.push_action(
    "nroom", 
    '{"host":"bob","guests":["carol","alice"]}', 
    sess.bob)


roomABC = '"host":"alice","guests":["carol","bob"]'

roomAB = '"host":"alice","guests":["bob"]'

messenger.push_action(
    "nroom", 
    '{'+roomABC+'}',
     sess.alice
)

messenger.push_action(
    "npost", 
    '{'+ roomABC +','+
    '"by":"alice",'+
    '"message":"Hello message 1"}', 
    sess.alice
)

messenger.push_action(
    "npost", 
    '{'+ roomABC +','+
    '"by":"carol",'+
    '"message":"Hello message 2"}', 
    sess.carol
)
'''
messenger.push_action(
    "npost", 
    '{'+ roomAB +','+
    '"by":"carol",'+
    '"message":"Hello message 2"}', 
    sess.carol
)
'''
messenger.table("rooms",sess.bob)
messenger.table("rooms",sess.alice)
messenger.table("posts",sess.alice)

node.info()

print("Alice")
print(sess.alice.active_key)

print("Carol")
print(sess.carol.active_key)

print("Bob")
print(sess.bob.active_key)


#node.stop()

# Delete room
# Delete post
# Check if npost is created by host or guests
# Blacklist account
# Notes/Blog
    # Add
    # Delete

# Frontend vue
# Scatter
# eosjs
# 

# Dapp token
# Buy/Sell (exchange) tokens
# Stake token
# Inflate token
# Delegate eos