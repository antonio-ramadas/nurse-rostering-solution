<template>
  <div class="wrapper">
    <page-header></page-header>
    <content-area></content-area>
  </div>
</template>

<script>
  import PageHeader from './LandingPageView/PageHeader'
  import ContentArea from './LandingPageView/ContentArea'
  export default {
    components: {
      PageHeader,
      ContentArea
    },
    name: 'landing-page'
  }

</script>

<style scoped>

  .wrapper {
    display: flex;
    flex-direction: column; 
  }

</style>