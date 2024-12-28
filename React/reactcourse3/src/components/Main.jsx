import React from "react"
import ClaudeRecipeComp from "./ClaudeRecipe"
import IngredientsListComp from "./IngredientsList"


function MainComp(){
    const [ingredients, setIngredients] = React.useState(["pasta", "ground beef","tomatoe sauce", "oregano"])
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
                {ingredients.length > 0 &&
                <IngredientsListComp ingredients={ingredients} getRecipe={getRecipe}/>}

                {recipeShown && <ClaudeRecipeComp />}
        </main>
    )
}

export default MainComp