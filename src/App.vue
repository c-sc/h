<template>
  <div id="app">
    <Main/>
  </div>
</template>

<script>
import Main from './components/Main';

export default {
  name: 'App',
  components: {
    Main,
  },
};
</script>

<style>
* {
  padding: 0;
  margin: 0;
}
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
}
#topright {
  margin-top: 11px;
  float: right;
  vertical-align: center;
}
.lbtn {
  margin-left: 8px;
}
</style>
