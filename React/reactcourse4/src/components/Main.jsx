import {useState} from "react"

function MainComp(){
    const [meme, setMeme] = useState({
        topText : "One does not simply",
        bottomText : "walk into Mordor",
        imgURL : "//i.imgflip.com/1bij.jpg"
    })

    function handleChange(event){
        const {value, name} = event.currentTarget
        setMeme(prevMeme => ({
                ...prevMeme,
                [name] : value
        }))
    }

    return <main>
        <div  className="form">
            <label>
                Upper text
                <input type="text" 
                       placeholder="One does not simply"
                       name="topText"
                       onChange={handleChange}
                       value={meme.topText}
                       />
            </label>

            <label>
                Lower text
                <input type="text" 
                       placeholder="walk into Mordor."
                       name="bottomText"
                       onChange={handleChange}
                       value={meme.bottomText}/>
            </label>
        <button>Get new meme image</button>
        </div>
        <div className="meme">
            <img src={meme.imgURL}/>
            <span className="top">{meme.topText}</span>
            <span className="bottom">{meme.bottomText}</span>
        </div>
    </main>
}

export default MainComp