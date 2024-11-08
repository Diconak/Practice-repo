namespace Basket.API.Entities
{
    public class ShoppingCart
    {

        public string Username { get; set; }
        public List<ShoppingCartItem> Items = new List<ShoppingCartItem>();
        public decimal TotalPrice; 
        public ShoppingCart(string username = null) { 
            Username = username ?? throw new ArgumentNullException(nameof(username)); 
        }
    }
}
