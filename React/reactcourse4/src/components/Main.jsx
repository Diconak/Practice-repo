import {useState, useEffect} from "react"

function MainComp(){
    const [meme, setMeme] = useState({
        topText : "One does not simply",
        bottomText : "walk into Mordor",
        imgURL : "//i.imgflip.com/1bij.jpg"
    })

    const [allMemes, setAllMemes] = useState([])
 
    useEffect(() => {
        fetch("https://api.imgflip.com/get_memes")
            .then(res => res.json())
            .then(data => setAllMemes(data.data.memes))
        })

    function handleChange(event){
        const {value, name} = event.currentTarget
        setMeme(prevMeme => ({
                ...prevMeme,
                [name] : value
        }))
    }

    function getRandomImage(){
        const randomNumber = Math.floor(Math.random() * allMemes.length)
        const newMemeUrl = allMemes[randomNumber].url
        setMeme(prevMeme => ({
            ...prevMeme,
            imgURL : newMemeUrl
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
        <button onClick={getRandomImage}>Get new meme image</button>
        </div>
        <div className="meme">
            <img src={meme.imgURL}/>
            <span className="top">{meme.topText}</span>
            <span className="bottom">{meme.bottomText}</span>
        </div>
    </main>
}

export default MainComp