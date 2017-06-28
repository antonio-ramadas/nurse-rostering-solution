<template>
    <div class="mainContainer">

        <div class="tableContainer"  v-for="i in numberOfWeeks">

            <h1>Week {{ i }} </h1>

            <table class="tableWeek">
                <tr>
                    <th>Week</th>
                    <th v-for="day in weekDays" :colspan="skills.length"> {{ day }} </th>
                </tr>

                <tr>
                    <th>Skill</th>
                    <template v-for="i in weekDays.length">
                        <th v-for="skill in skills"> {{ skill }} </th>
                    </template>
                </tr>

                <tr v-for="nurse in nurses[i-1]">
                    <th class="personName"> {{ nurse.name }} </th>
                    <td v-for="assign in nurse.assignments">
                        <img title="Morning" v-show="assign === 'Early'" src="./assets/day.png" alt="Morning">
                        <img title="Evening" v-show="assign === 'Evening'" src="./assets/evening.png" alt="">
                        <img title="Noon" v-show="assign === 'Late'" src="./assets/noon.png" alt="">
                        <img title="Night" v-show="assign === 'Night'" src="./assets/night.png" alt="">
                        <img title="Skill Not Learned" v-show="assign === 'null'" src="./assets/negative.png" alt="">
                    </td>
                </tr>

                <!--</table class="tableConstraints">
                <thead>
                <tr>
                    <th>Constraints</th>
                    <th>Score</th>
                </tr>
                </thead>
                <tbody>
                <tr>
                    <th>Total Assignment</th>
                    <td></td>
                </tr>
                <tr>
                    <th>Consecutive</th>
                    <td></td>
                </tr>
                <tr>
                    <th>Non-Working Days</th>
                    <td></td>
                </tr>
                <tr>
                    <th>Preferences</th>
                    <td></td>
                </tr>
                <tr>
                    <th>Max woriking Weekend</th>
                    <td></td>
                </tr>
                <tr>
                    <th>Complete Weekends</th>
                    <td></td>
                </tr>
                <tr>
                    <th>Optimal Coverage</th>
                    <td></td>
                </tr>
                </tbody>
                </table>-->
            </table>
        </div>

    </div>
</template>

<script>
    const fs = require('fs')

    let nurses = [], skills = [], originalNurses = []

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
                skills: [],
                nurses: [[
                    { name: 'Arminda', assignments: ['night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night', 'night'] },
                    { name: 'Genoveva', assignments: ['noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon', 'noon'] },
                    { name: 'Libânia', assignments: ['evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening', 'evening'] },
                    { name: 'Teodora', assignments: ['null', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day', 'day'] }
                ]],
                numberOfWeeks: 0
            }
        },
        mounted() {
            fs.readFile('../tools/Sc-n005w4.json', 'utf8', (err, data) => {
                if (err !== null) {
                    throw `Error: Scenario not found (${err})`
                }

                let scenario = JSON.parse(data)

                skills = scenario.skills

                this.$set(this, 'skills', skills)
                this.$set(this, 'numberOfWeeks', scenario.numberOfWeeks)

                fillNursesAndSkills(this, scenario)

                parseSolutionFiles(this, '../tools/Sol-n005w4-', [1,2,3,3])
            })
        }
    }

    function fillNursesAndSkills(vueInstance, scenario) {
        let singleNurseWeek = []

        for (let nurse of scenario.nurses) {
            singleNurseWeek.push({name: nurse.id})
        }

        for (let i = 0; i < singleNurseWeek.length; i++) {
            let nurse = singleNurseWeek[i]

            // The number of columns is equal to the 7 days multiplied by the number of existing skills
            nurse.assignments = Array(7 * skills.length).fill('')

            //set null to invalid assignments
            let j = 0;
            for (let skill of skills) {
                if (scenario.nurses[i].skills.indexOf(skill) === -1) {
                    for (let ind = j; ind < 7*skills.length; ind += skills.length)
                        nurse.assignments[ind] = 'null'
                }
                j++
            }
        }

        nurses = []
        for (let i = 0; i < scenario.numberOfWeeks; i++)
            nurses.push(deepCopy(singleNurseWeek))

        originalNurses = deepCopy(nurses)

        vueInstance.$set(vueInstance, 'nurses', nurses)
    }

    function parseSolutionFiles(vueInstance, path, filesIndex) {
        setInterval(() => {
            vueInstance.$set(vueInstance, 'nurses', nurses)
            nurses = deepCopy(originalNurses)

            for (let i = 0; i < filesIndex.length; i++) {
                fs.readFile(path + filesIndex[i] + '-' + i + '.json', 'utf8', (err, data) => {
                    if (err === null)
                        fillWeek(vueInstance, JSON.parse(data))
                })
            }
            }, 100)
    }

    function fillWeek(vueInstance, weekData) {
        const weekdays = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']

        for (let nurse of nurses[weekData.week]) {
            let nurseAssignments = weekData.assignments.filter(value => value.nurse === nurse.name)

            for (let assignment of nurseAssignments) {
                let index = weekdays.indexOf(assignment.day) * skills.length + skills.indexOf(assignment.skill)
                nurse.assignments[index] = assignment.shiftType
            }
        }
    }

    function deepCopy(array) {
        return JSON.parse(JSON.stringify(array))
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
        margin-top: 3.5rem;
        margin-bottom: 2rem;
        flex: 1 1 auto;
    }

    .tableContainer {
        margin-top: 1rem
    }

    .personName {
        width: 80px;
    }

    .tableWeek {
        table-layout: fixed;
        width: 1700px;
        border-collapse: collapse;
        margin-bottom: 2rem;
        border: 1px groove white;
        box-shadow: 1px 1px 10px grey;
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
    h1:hover {
        color: red;
    }
</style>