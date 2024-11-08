using Catalog.API.Data;
using Catalog.API.Entities;
using MongoDB.Driver;

namespace Catalog.API.Repositories
{
    //Ovo je klasa koja implementira interfejs, u ovom slucaju posto koristimo mongo biblioteku, povlacimo podatke iz mongo konteksta
    // i radimo direktno sa njima.
    public class ProductRepository : IProductRepostories
    {

        private readonly ICatalogContext _context;
        public ProductRepository(ICatalogContext context) { 
        
            _context = context ?? throw new ArgumentNullException(nameof(context));
        }

        public async Task<IEnumerable<Product>> GetProducts()
        {
            return await _context.Products.Find(p => true).ToListAsync();
        }
    }
}
