using AutoMapper;
using Discount.Common.Repository;
using Discount.GRPC.Protos;
using Grpc.Core;

namespace Discount.GRPC.Services
{
    public class CouponService : CouponProtoService.CouponProtoServiceBase
    {

        private readonly ICouponRepository repository;
        private readonly IMapper mapper;
        private readonly ILogger logger;

        public CouponService(ICouponRepository repository, IMapper mapper, ILogger logger)
        {
            this.repository = repository;
            this.mapper = mapper;
            this.logger = logger;
        }

        public override async Task<GetDiscountResponse> GetDiscount(GetDiscountRequest request, ServerCallContext context)
        {
            var coupon = await repository.GetDiscount(request.ProductName);
            logger.LogInformation("Get discount for product: {ProductName} was found", request.ProductName);

            return mapper.Map<GetDiscountResponse>(coupon);
        }

        public override async Task<GetRandomDiscountResponse> GetRandomDiscount(GetRandomDiscountRequest request, ServerCallContext context)
        {
            var coupon = await repository.GetRandomDisounts(request.NumOfRequests);
            var response = new GetRandomDiscountResponse();

            response.Coupons.AddRange(mapper.Map<IEnumerable<GetRandomDiscountResponse.Types.Coupon>>(coupon));
            response.TotalAmount = coupon.Sum(count => count.Amount);
            logger.LogInformation("GetRandomDiscounts returned random disocunts");

            return response;
        }
    }
}
