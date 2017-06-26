<template>
    <div class="mainContainer">

        <div class="tableContainer"  v-for="i in 2">

            <h1>Week {{ i }} </h1>

            <table>
                <tr>
                    <th>Week</th>
                    <th v-for="day in weekDays" colspan="3"> {{ day }} </th>
                </tr>

                <tr>
                    <th>Skill</th>
                    <th v-for="skill in getAllSkills(weekDays, skills)"> {{ skill }} </th>
                </tr>

                <tr v-for="nurse in nurses">
                    <th class="personName"> {{ nurse.name }} </th>
                    <td v-for="assign in nurse.assignments">
                        <img title="Morning" v-show="assign === 'day'" src="./assets/day.png" alt="Morning">
                        <img title="Evening" v-show="assign === 'evening'" src="./assets/evening.png" alt="">
                        <img title="Noon" v-show="assign === 'noon'" src="./assets/noon.png" alt="">
                        <img title="Night" v-show="assign === 'night'" src="./assets/night.png" alt="">
                    </td>
                </tr>

            </table>

        </div>

    </div>
</template>

<script>
    export default {
        name: 'mainContainer',
        data() {
            return {
                weekDays: [
                    'Sunday',
                    'Monday',
                    'Tuesday',
                    'Wednesday',
                    'Thursday',
                    'Friday',
                    'Saturday'
                ],
                skills: [
                    'Head Nurse',
                    'Nurse',
                    'Surgeon'
                ],
                nurses: [
                    { name: 'Arminda', assignments: ['night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night'] },
                    { name: 'Genoveva', assignments: ['noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon'] },
                    { name: 'Libânia', assignments: ['evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening'] },
                    { name: 'Teodora', assignments: ['day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day'] }
                ]
            }
        },
        methods: {
            getAllSkills: function (weekDays, skills) {
                let array = [];
                for (let i = 0; i < weekDays.length * skills.length; i++) {
                    array.push(skills[i % skills.length]);
                }
                return array;
            }
        }
    }

</script>

<style>
    .mainContainer {
        z-index: -1;
        display: flex;
        align-items: center;
        text-align: center;
        justify-content: center;
        flex-direction: column;
        margin-top: 3rem;
        margin-bottom: 2rem;
        flex: 1 1 auto;
    }

    .tableContainer {
        margin-top: 1rem
    }
    
    .personName {
        width: 80px;
    }

    table {
        table-layout: fixed;
        width: 1700px;
        border-collapse: collapse;
        margin-bottom: 2rem;
        border: 1px groove white;
    }

    table,
    th,
    td {
        border: 1px groove white;
        font-size: 1rem;
    }

    th,
    td {
        padding: 0.4em;
    }

    th {
        background-color: #FFFFF0;
    }

    td {
        background-color: aliceblue;
        padding: 0;
    }
    td:hover {
        background-color: black;
    }

    img {
        width: 60px;
        height: 60px;
        padding-top: 2px;
    }
    
    tr:hover {
        background-color: aquamarine;
    }
</style>