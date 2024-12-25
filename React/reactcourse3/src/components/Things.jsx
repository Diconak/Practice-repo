import React from "react"

function ThingsComp(){
    
    const [myFavoriteThings, setMyFavoriteState] = React.useState([])
    const allFavoriteThings = ['Vetar','Voda', 'Vatra', 'Zemlja']

    const thingsElements = myFavoriteThings.map(thing => <p key={thing}>{thing}</p>)

    function addFavoriteThing(){
        setMyFavoriteState(prevFavThings => [...prevFavThings, allFavoriteThings[prevFavThings.length]])
    }
    return (
        <main className="thingsMain">
            <button  onClick={addFavoriteThing}>Add Item</button>
            <section aria-live="polite">
                {thingsElements}
            </section>
        </main>
    )
}

export default ThingsComp