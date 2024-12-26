import React from "react"

function JokesComp(props){
    const [isShown, setIsShown] = React.useState(false)
    function ShowJoke(){
        setIsShown(prevIsShown => !prevIsShown)
        console.log(isShown)
    }
    return(
        <>
            {props.setup && <p>Setup: {props.setup}</p>}
            {isShown && <p>Punchline: {props.punchline}</p> }
            <button onClick={ShowJoke}>{isShown ? "Hide" : "Show"}</button>
            <hr />
        </>
    )
}

export default JokesComp