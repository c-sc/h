<template>
  <div id="header" >
    <div  class="container">
      <img id="logo" src="https://github.com/gitgyver/test/blob/master/codescape2.png?raw=true">
      <div id="topright">
        <a href="https://github.com/gitgyver">
          <button type="button" class="btn btn-primary btn-light lbtn" >Github</button>
        </a>
          <button type="button" class="btn btn-primary btn-light lbtn">Showcase</button>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'Header',
  components: {},
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
