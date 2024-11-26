using Basket.API.Entities;
using Basket.API.GrpcServices;
using Basket.API.Repository;
using Microsoft.AspNetCore.Mvc;

namespace Basket.API.Controllers
{
    [ApiController]
    [Route("api/v1/[controller]")]
    public class BasketController : ControllerBase
    {
        private readonly IBasketRepository _basketRepository;
        private readonly ILogger<BasketController> _logger;
        private readonly CouponGrpcService _couponService;

        public BasketController(IBasketRepository basketRepository, ILogger<BasketController> logger, CouponGrpcService couponGrpcService) { 
            _basketRepository = basketRepository ?? throw new ArgumentNullException(nameof(basketRepository));
            _logger = logger ?? throw new ArgumentNullException(nameof(_logger));
            _couponService = couponGrpcService ?? throw new ArgumentNullException(nameof(couponGrpcService));
        }

        [HttpGet("{username}")]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status404NotFound)]
        public async Task<ActionResult<ShoppingCart>> GetBasket(string username) { 
            var basket = await _basketRepository.GetBasket(username);
            if (basket == null) { 
                return NotFound();
            }
            return Ok(basket ?? new ShoppingCart(username));
        }

        [HttpPut]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status404NotFound)]
        public async Task<ActionResult<ShoppingCart>> UpdateBasket([FromBody] ShoppingCart basket) {

            foreach (var item in basket.Items)
            {

                try
                {

                    var coupon = await _couponService.GetDiscount(item.ProductName);
                    item.Price -= coupon.Amount;

                }
                catch (Exception ex)
                {
                    _logger.LogInformation("Error while retreaving coupon");
                }

            }

            return Ok(_basketRepository.UpdateBasket(basket));
        }

        [HttpDelete]
        [ProducesResponseType(typeof(ShoppingCart), StatusCodes.Status200OK)]
        public async Task<ActionResult> DeleteBasket(string username) { 
            await _basketRepository.DeleteBasket(username);
            return Ok();
        } 
    }
}
