import React from "react"

function MainComp(){
    const [ingredients, setIngredients] = React.useState(["pasta", "ground beef","tomatoe sauce", "oregano"])
    const htmlIngredients = ingredients.map((elem) => {
        return <li key={elem}>{elem}</li>
    }) 

    const [recipeShown, setRecipeShown] = React.useState(false)

    function onSubmit(formData){
        const newIngredient = formData.get("ingredient")
        setIngredients(prevIngredient => [...prevIngredient, newIngredient])
    }

    function getRecipe(){
        setRecipeShown(prevRecipe => !prevRecipe)
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
            <section>
                {   ingredients.length > 0 ?
                    <>
                    <h2>Ingredients on hand:</h2>
                    <ul className="ingredientsList" aria-live="polite">{htmlIngredients}</ul>
                    {ingredients.length > 3 ? <div className="getRecipeContainer">
                        <div>
                            <h3>Ready for recipe</h3>
                            <p>Generate recipe from your list of ingredients.</p>
                        </div>
                        <button onClick={getRecipe}>Get a recipe</button>
                    </div>  : null  }
                </>
                : null  }
            </section>
            <section>
                {recipeShown && <p>This is where Claude-3 AI is going</p>}
            </section>
        </main>
    )
}

export default MainComp