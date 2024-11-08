using Basket.API.Entities;
using Microsoft.Extensions.Caching.Distributed;
using Newtonsoft.Json;

namespace Basket.API.Repository
{
    public class BasketRepository : IBasketRepository
    {
        //Ovde bismo inace iz data foldera koristili onaj seed, ali to za redis ima implementirano od strane Microsofta
        private readonly IDistributedCache _cache;

        public BasketRepository(IDistributedCache cache) { 
            _cache = cache ?? throw new ArgumentNullException(nameof(cache));
        }
        public async Task<ShoppingCart> GetBasket(string username) { 
            var basket = await _cache.GetStringAsync(username);
            if (String.IsNullOrEmpty(basket)) {
                return null;
            }
            return JsonConvert.DeserializeObject<ShoppingCart>(basket);
        }
        public async Task<ShoppingCart> UpdateBasket(ShoppingCart basket) { 
            var basketString = JsonConvert.SerializeObject(basket);
            await _cache.SetStringAsync(basket.Username, basketString);
            return await GetBasket(basket.Username);
        }
        public async Task DeleteBasket(string username) { 
            await _cache.RemoveAsync(username);
        
        }
    }
}
