﻿using Catalog.API.Data;
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

        public async Task<Product> GetProductByID(string id) { 
            return await _context.Products.Find(p => p.Id == id).FirstOrDefaultAsync();
        }
        public async Task<IEnumerable<Product>> GetProductByCategory(string category) { 
            return await _context.Products.Find(p => p.Category == category).ToListAsync();
        }
        public async Task CreateProduct(Product product) { 
            await _context.Products.InsertOneAsync(product);
        }
        public async Task<bool> UpdateProduct(Product product) {
            var updateResult = _context.Products.ReplaceOneAsync(p => p.Id == product.Id, product);
            return updateResult.IsCompleted && updateResult.Result.ModifiedCount > 0;
        }
        public async Task<bool> DeleteProduct(string id) { 
            var deleteProduct = _context.Products.DeleteOneAsync(p => p.Id == id);
            return deleteProduct.IsCompleted;
        }
    }
}
