using Discount.GRPC.Protos;
using System.Diagnostics.CodeAnalysis;

namespace Basket.API.GrpcServices
{
    public class CouponGrpcService
    {
        private readonly CouponProtoService.CouponProtoServiceClient _couponProtoServiceClient;

        public CouponGrpcService(CouponProtoService.CouponProtoServiceClient couponProtoServiceClient)
        {
            _couponProtoServiceClient = couponProtoServiceClient ?? throw new ArgumentNullException(nameof(couponProtoServiceClient));
        }

        public async Task<GetDiscountResponse> GetDiscount(string productName) {
        
            var discount = new GetDiscountRequest();
            discount.ProductName = productName;
            return await _couponProtoServiceClient.GetDiscountAsync(discount);
        }

        public async Task<GetRandomDiscountResponse> GetRandomDiscount(int numOfDiscount) {
        
            var randomDiscount = new GetRandomDiscountRequest();
            randomDiscount.NumOfRequests = numOfDiscount;
            return await _couponProtoServiceClient.GetRandomDiscountAsync(randomDiscount);
        }

    }
}
