using Discount.Common.DTOs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Discount.Common.Repository
{
    internal interface ICouponRepository
    {
        Task<CouponDTO> GetDiscount(string productName);
        Task<bool> CreateDiscount(CreateCouponDTO coupon);
        Task<bool> UpdateDiscount(UpdateCouponDTO coupon);
        Task DeleteDiscount(string productName);
        Task<IEnumerable<CouponDTO>> GetRandomDisounts(int numberOfDiscounts);
    }
}
