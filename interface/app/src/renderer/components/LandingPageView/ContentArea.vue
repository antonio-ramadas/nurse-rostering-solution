<template>
    <div class="mainContainer">

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
                <th> {{ nurse.name }} </th>
            </tr>

        </table>

    </div>
</template>

<script>
    export default {
        name: 'mainContainer',
        data() {
            return {
                weekDays : [
                    'Sunday',
                    'Monday',
                    'Tuesday',
                    'Wednesday',
                    'Thursday',
                    'Friday',
                    'Saturday'
                ],
                skills : [
                    'Head Nurse',
                    'Nurse',
                    'Surgeon'
                ],
                nurses : [
                    { name: 'Arminda' },
                    { name: 'Genoveva' },
                    { name: 'Libânia' },
                    { name: 'Teodora' }
                ]
            }
        },
        methods: {
            getAllSkills: function(weekDays, skills) {
                let array = [];
                for (let i = 0; i < weekDays.length * skills.length; i++) {
                    array.push(skills[i % skills.length]);
                }
                return array;
            }
        }
    }
</script>

<style scoped>
    .mainContainer {
        z-index: -1;
        background-color: #FFFFF0;
        display: flex;
        align-items: center;
        text-align: center;
        justify-content: center;
    }

    table {
        height: 0%;
        max-width: 100%;
        border-collapse: collapse;
    }

    table,
    th,
    td {
        border: 3px groove brown;
        font-size: 1rem;
    }

    th,
    td {
        padding: 0.4em;
    }

    th {
        background-color: white;
    }

    td {
        background-color: aliceblue;
    }
</style>