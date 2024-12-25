import React from "react"
import ReactDOM from "react-dom/client"

function FormComp(){

    function signUp(formData){
        const email = formData.get("email")
        const password = formData.get("password")
        const employment = formData.get("employmentStatus")
        const diet = formData.getAll("diet")
        //More efficient method, does not always work
        //in this example the diet has to be added seperatily
        const data = Object.entries(formData)
        console.log(data)
    }

    return(
        <main className="formCompMain">
            <h1>Form goes here</h1>
            <form action={signUp}>
                <label>Email:</label><br />
                <input className="email" id="email" type="email" name="email"/>
                <br />
                <label >Password:</label><br />
                <input className="password" id="password" type="password" name="password" />
                <br />

                <label htmlFor="description">Description:</label><br />
                <textarea name="description" id="description"></textarea>
                <br />

            <fieldset>
                <legend>Employment Status:</legend>
                <label>
                    <input type="radio" name="employmentStatus" value="unemployed" />
                    Unemployed
                </label><br />
                <label>
                    <input type="radio" name="employmentStatus" value="Part-time"/>
                    Part-time
                </label><br /> 
                <label>
                    <input type="radio" defaultChecked={true} name="employmentStatus" value="Full-time"/>
                    Full-time
                </label>
            </fieldset>
            
            <fieldset>
                <legend>Dietary restrictions:</legend>
                <label>
                    <input type="checkbox" name="diet" value="kosher" />
                    Kosher
                </label><br />
                <label>
                    <input type="checkbox" name="diet" value="vegan"/>
                    Vegan
                </label><br />
                <label>
                    <input type="checkbox" defaultChecked={true} name="diet" value="glutten free"/>
                    Glutten Free
                </label>
            </fieldset>
            <label htmlFor="favColor"> What is your favorite color?</label>
            <select name="favColor" id="favColor" defaultValue="">
                <option value="" disabled>--Choose a color--</option>
                <option value="Red">Red</option>
                <option value="Blue">Blue</option>
                <option value="Green">Green</option>
            </select>
                <br />
                <button className="formCompSubmit">Submit</button>
            </form>

        </main>
    )
}

export default FormComp