using Microsoft.AspNetCore.Mvc;
using Discount.Common.Repository;
using Discount.Common.DTOs;
using System.Globalization;

namespace Discount.API.Controllers
{

    [ApiController]
    [Route("api/[controller]")]
    public class DiscountController : ControllerBase
    {
        private readonly ICouponRepository _repository;
        public DiscountController(ICouponRepository repository) {
            _repository = repository ?? throw new ArgumentNullException(nameof(repository));
        
        }

        public async Task<ActionResult<CouponDTO>> GetDiscount(string ProductName) { 
            var response = await _repository.GetDiscount(ProductName);
            if(response == null)
                return NotFound();
            return Ok(response);
        } 
    }
}
