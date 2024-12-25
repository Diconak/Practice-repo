import React from "react"

function MainComp(){
    const [ingredients, setIngredients] = React.useState([])
    const htmlIngredients = ingredients.map((elem) => {
        return <li key={elem}>{elem}</li>
    }) 

    function onSubmit(formData){
        const newIngredient = formData.get("ingredient")
        setIngredients(prevIngredient => [...prevIngredient, newIngredient])
    }

    return(
        <main>
            <form className="addIngredientForm" action={onSubmit}>
                <input 
                    type="text"
                    placeholder="e.g. oregano"
                    aria-label="Add ingredient" 
                    name="ingredient"
                />
                <button >Add ingredient</button>
            </form>
            <ul>
                {htmlIngredients}
            </ul>
        </main>
    )
}

export default MainComp