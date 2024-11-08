using Basket.API.Entities;
using Basket.API.Repository;
using Microsoft.AspNetCore.Mvc;

namespace Basket.API.Controllers
{
    [ApiController]
    [Route("api/v1/[controller]")]
    public class BasketController : ControllerBase
    {
        private readonly IBasketRepository _basketRepository;
        public BasketController(IBasketRepository basketRepository) { 
            _basketRepository = basketRepository ?? throw new ArgumentNullException(nameof(basketRepository));
        }

        [HttpGet("username")]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status404NotFound)]
        public async Task<ActionResult<ShoppingCart>> GetBasket(string username) { 
            var basket = await _basketRepository.GetBasket(username);
            if (basket == null) { 
                return NotFound();
            }
            return Ok(basket);
        }

        [HttpPut]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status404NotFound)]
        public async Task<ActionResult<ShoppingCart>> UpdateBasket(ShoppingCart basket) { 
            var cart = await _basketRepository.UpdateBasket(basket);
            if (cart == null) {
                return NotFound();
            }
            return Ok(cart);
        }

        [HttpDelete]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status200OK)]
        public async Task<ActionResult> DeleteBasket(string username) { 
            await _basketRepository.DeleteBasket(username);
            return Ok();
        } 
    }
}
