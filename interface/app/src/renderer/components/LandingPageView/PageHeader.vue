<template>
  <div class="pageHeader">
    <p>
      Nurse Manager
    </p>
  </div>
</template>

<script>
  export default {
    created() {
      // Set $route values that are not preset during unit testing
      if (process.env.NODE_ENV === 'testing') {
        this.$route = {
          name: 'landing-page',
          path: '/landing-page'
        }
      }
    }
  }

</script>

<style>
  .pageHeader {
    position: fixed;
    width: 100%;
    display: flex;
    background-color: #F6F657;
    align-items: center;
    text-align: center;
    justify-content: center;
    box-shadow: 1px 0px 10px grey;
    height: 2.5em;
  }

  p {
    font-weight: bold;
    max-height: 50%;
  }
</style>