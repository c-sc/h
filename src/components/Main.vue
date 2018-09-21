<template><div><div id="header" ><div  class="container">
<img id="logo" src="https://github.com/gitgyver/test/blob/master/codescape2.png?raw=true">
<div id="topright">
  <a href="https://github.com/gitgyver">
  <button type="button" class="btn btn-primary btn-light lbtn">
  <img id="logo" src="http://icons.iconarchive.com/icons/artcore-illustrations/artcore-4/24/github-icon.png">Github
  </button>
  </a>
  <button @click="mc = 'Showcase'" type="button" class="btn btn-primary btn-light lbtn">
    Showcase
  </button>
  <button @click="mc = 'Dapps'" type="button" class="btn btn-primary btn-light lbtn">
    Dapps
  </button>
</div></div></div>
  <div class="container-fluid">
    <component :is="mc"></component>
  </div>
</div></template>

<script>
import Showcase from './Showcase';
import Dapps from './Dapps';

export default {
  name: 'Main',
  components: {
    Showcase,
    Dapps,
  },
  data() {
    return {
      mc: 'Showcase',
    };
  },
  methods: {
  },
};
</script>

<style>
#header {
  max-height: 60 px;
  height: 60 px;
  width: 100%;
  background-color: rgb(60, 122, 192);
}
#logo {
  max-width: 70px;
  max-height: 60px;
  float: left;
}
#topright {
  margin-top: 11px;
  float: right;
  vertical-align: center;
}
.lbtn {
  margin-left: 8px;
}
.container {
  margin: 0 auto;
  height: 60px;
}
</style>
