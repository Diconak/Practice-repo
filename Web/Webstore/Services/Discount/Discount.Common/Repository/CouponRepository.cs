using AutoMapper;
using Dapper;
using Discount.Common.Data;
using Discount.Common.DTOs;
using Discount.Common.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Discount.Common.Repository
{
    public class CouponRepository : ICouponRepository
    {

        private readonly ICouponContext _context;
        private readonly IMapper _mapper;

        public CouponRepository(ICouponContext couponContext, IMapper mapper)
        {
            _context = couponContext;
            _mapper = mapper;
        }

        public async Task<CouponDTO> GetDiscount(string productName)
        {

            using var connection = _context.GetConnection();
            const string sql = "select * from Coupon where ProductName = @ProductName";
            var coupon = await connection.QueryFirstOrDefaultAsync<Coupon>(sql, new { ProductName = productName });

            return _mapper.Map<CouponDTO>(coupon);
            
        }
        public async Task<bool> CreateDiscount(CreateCouponDTO coupon)
        {
            using var connection = _context.GetConnection();
            int affected = await connection.ExecuteAsync(
                "insert into Coupon(ProductName, Amount, Description) values (@ProductName, @Amount, @Description)"
                , new { ProductName = coupon.ProductName, Amount = coupon.Amount, Description =coupon.Description}
                );
            return affected > 0;
        }

        public async Task<bool> UpdateDiscount(UpdateCouponDTO coupon)
        {
            using var connection = _context.GetConnection( );
            int affected = await connection.ExecuteAsync(
                "update Coupon set ProductName = @ProductName, Amount = @Amount,Description = @Description"
                ,new { ProductName = coupon.ProductName, Amount = coupon.Amount, Description = coupon.Description}
                );
            return affected > 0;
        }

        public Task DeleteDiscount(string productName)
        {
            throw new NotImplementedException();
        }

        public async Task<IEnumerable<CouponDTO>> GetRandomDisounts(int numberOfDiscounts)
        {
            using var connection = _context.GetConnection();
            var coupons = await connection.QueryAsync<Coupon>("select * from Coupon");
            if (coupons.Count() < numberOfDiscounts)
                return _mapper.Map<IEnumerable<CouponDTO>>(coupons);

            var random = new Random();
            return _mapper.Map<IEnumerable<CouponDTO>>(
                coupons
                    .Select(coupon => new { rang = random.Next(), item = coupon })
                    .OrderBy(obj => obj.rang)
                    .Select(obj => obj.item)
                    .Take(numberOfDiscounts)
                );
        }

    }
}
