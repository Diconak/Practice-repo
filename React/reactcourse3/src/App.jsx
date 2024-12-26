import HeaderComp from "./components/Header"
import MainComp from "./components/Main"
import ThingsComp from "./components/Things"
import FormComp from "./components/FormComp"
import JokesComp from "./components/Jokes"
import jokesData from "./assets/jokesData"

function App() {
    const jokes = jokesData.map((loc) => {
        return (<JokesComp
            setup = {loc.setup}
            punchline = {loc.punchline}
        />)
    })
 return(
    <>
        <HeaderComp/>
        <MainComp/>
    </>
 )
}

export default App
