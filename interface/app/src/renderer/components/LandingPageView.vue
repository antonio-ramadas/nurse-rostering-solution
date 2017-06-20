<template>
  <div class="wrapper">
    <page-header></page-header>
    <div id="content">
      <div id="col1">column1</div>
      <div id="col2">column2</div>
    </div>
  </div>
</template>

<script>
  import PageHeader from './LandingPageView/PageHeader'
  import PageBody from './LandingPageView/PageBody'
  export default {
    components: {
      PageHeader,
      PageBody
    },
    name: 'landing-page'
  }

</script>

<style scoped>
  .wrapper,
  html,
  bodym,
  * {
    margin: 0;
  }

  .wrapper {
    display: flex;
    flex-direction: column;
  }

  #content {
    flex: 2;
    display: flex;
  }

  #col1 {
    background-color: #F6F657;
    flex: 1;
  }

  #col2 {
    background-color: orange;
    flex: 6;
  }
</style>