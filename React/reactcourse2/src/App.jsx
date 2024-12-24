import HeaderComp from "./components/Header"
import EntryComp from "./components/Entry"
import JokesComp from "./components/Jokes"
import data from "./assets/data"

function App(){
    const desitnations = data.map((loc) => {
        return (<>
            <EntryComp 
                key = {loc.id}
                entry = {loc}
            />
        </>)
    })
    return (<>
        <HeaderComp/>
        <main className="containerDestination">
            {desitnations}
        </main>
    </>
    )
}

export default App