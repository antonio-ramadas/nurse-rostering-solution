<template>
  <div class="wrapper">
    <page-header></page-header>
    <div id="content">
      <side-menu id="col1"></side-menu>
      <content-area id="col2"></content-area>
    </div>
  </div>
</template>

<script>
  import PageHeader from './LandingPageView/PageHeader'
  import SideMenu from './LandingPageView/SideMenu'
  import ContentArea from './LandingPageView/ContentArea'
  export default {
    components: {
      PageHeader,
      SideMenu,
      ContentArea
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
    flex: 1;
  }

  #col2 {
    flex: 6;
  }
</style>