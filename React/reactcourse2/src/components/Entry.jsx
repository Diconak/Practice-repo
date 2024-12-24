
function EntryComp(props){
    return(
        <article className="entryArticle">
            <div className="mainImageContainter">
                <img className="mtFujiImg" src={props.entry.img.src} alt={props.entry.img.alt} />
            </div>
            <div className="entryHeader">
                <img className="location" src="src/assets/location.jpg" alt="Location image"/>
                <span className="entrySpan">{props.entry.country}</span>
                <a className="entryA" 
                    href={props.entry.googleMapsLink}>
                        View on Google Maps</a>
                <p className="entryH1">{props.entry.title}</p>
                <p className="entryH4">{props.entry.dates}</p>
                <p className="entryParagraph">{props.entry.text}</p>
            </div>
                
        </article>
    )
}

export default EntryComp