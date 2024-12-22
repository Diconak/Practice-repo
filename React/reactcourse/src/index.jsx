import {createRoot} from "react-dom/client"

const root = createRoot(document.getElementById("root"))


function ReactFacts(){
    const logo = 
        <main>
            <img className="logo" src="/src/assets/React_Native_Logo.png"/>
            <h1>Fun facts about React</h1>
            <ul>
                <li>Was first released in 2013</li>
                <li>Was originallz created by Jordan Walke</li>
                <li>Has well over 100k stars on Github</li>
                <li>Is maintained by Meta</li>
            </ul>
        </main>
    
    return logo
}

root.render(
    
    <ReactFacts/>
)