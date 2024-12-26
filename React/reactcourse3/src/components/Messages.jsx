import React from "react";

function MessagesComp(){
    const [unreadMessages, setUnreadMessages] = React.useState(['a', 'b'])

    return(
        <div>
            {unreadMessages.length > 0 && <h1>You have {unreadMessages.length} unread messages!</h1>}
        </div>
    )
}

export default MessagesComp