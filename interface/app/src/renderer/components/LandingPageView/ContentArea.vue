<template>
    <div>

        <table>
            <tr class="firstRow">
                <th>Time</th>
                <th>Sunday</th>
                <th>Monday</th>
                <th>Tuesday</th>
                <th>Wednesday</th>
                <th>Thursday</th>
                <th>Friday</th>
                <th>Saturday</th>
            </tr>

            <tr>
                <th>Morning</th>

                <td>Physics-1</td>
                <td>English</td>
                <td></td>
                <td>Chemestry-1</td>
                <td>Alzebra</td>
                <td>Physical</td>
                <td>Physical</td>
            </tr>

            <tr>
                <th>Noon</th>

                <td>Maths</td>
                <td>Chemestry-2</td>
                <td>Physics-1</td>
                <td>Hindi</td>
                <td>English</td>
                <td>Soft Skill</td>
                <td>Soft Skill</td>
            </tr>

            <tr>
                <th>Night</th>

                <td>Portuguese</td>
                <td>English</td>
                <td>Math-1</td>
                <td>Chemistry</td>
                <td>Physics</td>
                <td>Chem.Lab</td>
                <td>Chem.Lab</td>
            </tr>

        </table>

    </div>
</template>

<style scoped>
    div {
        z-index: -2;
        background-color: #FFFFF0;
        display: flex;
        align-items: center;
        text-align: center;
        justify-content: center;
    }

    table {
        height: 30%;
        max-height: 50%;
        border-collapse: collapse;
    }

    table,
    th,
    td {
        border: 3px groove brown;
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