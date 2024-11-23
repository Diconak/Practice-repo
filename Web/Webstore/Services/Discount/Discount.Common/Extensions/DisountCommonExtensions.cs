using Discount.Common.Data;
using Discount.Common.DTOs;
using Discount.Common.Entities;
using Discount.Common.Repository;
using Microsoft.Extensions.DependencyInjection;

namespace Discount.Common.Extensions
{
    public static class DisountCommonExtensions
    {
        public static void DiscountCommonExtensions(this IServiceCollection _service) {
            _service.AddScoped<ICouponContext, CouponContext>();
            _service.AddScoped<ICouponRepository, CouponRepository>();
            _service.AddAutoMapper(config => {
                config.CreateMap<Coupon, CouponDTO>().ReverseMap();
            });

        }
    
    }
}
