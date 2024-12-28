function IngredientsListComp(props){
    const htmlIngredients = props.ingredients.map((elem) => 
        <li key={elem}>{elem}</li>
    ) 
    return (<section>
                <h2>Ingredients on hand:</h2>
                <ul className="ingredientsList" aria-live="polite">{htmlIngredients}</ul>
                {props.ingredients.length > 3 ? <div className="getRecipeContainer">
                    <div>
                        <h3>Ready for recipe</h3>
                        <p>Generate recipe from your list of ingredients.</p>
                    </div>
                    <button onClick={props.getRecipe}>Get a recipe</button>
                </div>  : null  }
            </section>
)}

export default IngredientsListComp