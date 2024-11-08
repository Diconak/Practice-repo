namespace Basket.API.Entities
{
    public class ShoppingCart
    {

        public string Username { get; set; }
        //Moramo ovde da dodamo ovo get i set, da bi mogli da pristupimo Entitetu za ShoppingCartItem u schemi
        public List<ShoppingCartItem> Items { get; set; } = new List<ShoppingCartItem>();
        public decimal TotalPrice; 
        public ShoppingCart(string username = null) { 
            Username = username ?? throw new ArgumentNullException(nameof(username)); 
        }
    }
}
