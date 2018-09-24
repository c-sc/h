<template>
  <div><br><br>
    <h2>eosjs example</h2><br>
    <h3>Select network: </h3><br>
    <h4>httpEndpoint:</h4>
    <input v-model="econfig['endpoint']" type="text"><br>
    <h4>port:</h4>
    <input v-model="econfig['port']" type="text"><br><br>
    <button @click="lscatter()" >eosjs connect</button><br><br><br>
    <h4>chainId:</h4>
    <input v-model="econfig['chainId']" type="text"><br><br><br>
    <button @click="getBalances()" >Get balances</button><br><br>
    <label>alice balance:</label>
    <label ref="aliceMoney"></label><br>
    <label>alice private active key: </label><br>
    <input type="text"><br>
    <label>Transfer</label><br>
    <label>To: </label><input type="text">
    <button @click="lscatter()" >Send</button><br><br>
    <label>carol balance: </label>
    <label ref="carolMoney"></label><br>
    <label>carol private active key: </label><br>
    <input type="text"><br>
    <label>Transfer</label><br>
    <label>To: </label><input type="text">
    <button @click="lscatter()" >Send</button><br><br>
    <label>bob balance: </label>
    <label ref="bobMoney"></label><br>
    <label>bob private active key: </label><br>
    <input type="text"><br>
    <label>Transfer</label><br>
    <label>To: </label><input type="text">
    <button @click="lscatter()" >Send</button><br><br>
  </div>
</template>

<script>
import Eos from 'eosjs';

export default {
  name: 'EosjsDemo',
  components: {},
  data() {
    return {
      error: {
        info: null,
        alice: null,
        bob: null,
        carol: null,
      },
      info: null,
      eos: null,
      balvis: false,
      alice: {
        balance: '',
      },
      carol: {
        balance: '',
      },
      bob: {
        balance: '',
      },
      econfig: {
        chainId: '',
        keyProvider: '',
        endpoint: 'http://localhost',
        httpEndpoint: '',
        port: '8888',
        expireInSeconds: 60,
        broadcast: true,
        debug: false,
        sign: true,
      },
      token: {
        code: 'eosio.token',
        scope: '',
        table: 'accounts',
        json: true,
      },
      baltest: null,
    };
  },
  computed: {
  },
  methods: {
    lscatter() {
      this.econfig.httpEndpoint = `${this.econfig.endpoint}:${this.econfig.port}`;
      this.eos = Eos(this.econfig);
    },
    getBalances() {
      this.eos.getInfo((error, info) => {
        this.error.info = error;
        this.info = info;
      });
      this.eos.getAccount('alice', (error, acc) => {
        this.error.alice = error;
        this.alice = acc;
      });
      this.eos.getAccount('carol', (error, acc) => {
        this.error.carol = error;
        this.carol = acc;
      });
      this.eos.getAccount('bob', (error, acc) => {
        this.error.bob = error;
        this.bob = acc;
      });
      this.token.scope = 'alice';
      this.eos.getTableRows(this.token, (errorA, rowsA) => {
        this.error.alice = errorA;
        this.alice.balance = rowsA.rows[0].balance;

        this.token.scope = 'carol';
        this.eos.getTableRows(this.token, (errorC, rowsC) => {
          this.error.carol = errorC;
          this.carol.balance = rowsC.rows[0].balance;

          this.token.scope = 'bob';
          this.eos.getTableRows(this.token, (errorB, rowsB) => {
            this.token.scope = '';
            this.error.bob = errorB;
            this.bob.balance = rowsB.rows[0].balance;
            this.balvis = !this.balvis;
          });
        });
      });
    },
  },
  watch: {
    balvis() {
      this.$refs.aliceMoney.innerHTML = this.alice.balance;
      this.$refs.carolMoney.innerHTML = this.carol.balance;
      this.$refs.bobMoney.innerHTML = this.bob.balance;
    },
  },
};
</script>

<style>

</style>
