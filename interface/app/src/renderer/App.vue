<template>
  <div id="app">
    <router-view></router-view>
  </div>
</template>

<script>
  import store from 'renderer/vuex/store'
  export default {
    store
  }

</script>

<style>
  @import url(https://fonts.googleapis.com/css?family=Lato:300);

  * {
  }

  html,
  body {
    margin: 0;
    padding: 0;
  }

  body {
    font-family: Lato, Helvetica, sans-serif;
    background-color:rgb(250,250,250);
    height: 100%;
    min-height: 100%;
  }
</style>