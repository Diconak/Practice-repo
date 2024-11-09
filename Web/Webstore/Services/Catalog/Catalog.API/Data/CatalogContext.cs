using Catalog.API.Entities;
using MongoDB.Driver;
using MongoDB.Driver.Core.Configuration;

namespace Catalog.API.Data
{
    public class CatalogContext : ICatalogContext
    {

        public CatalogContext(IConfiguration configuration) 
        {
            var client = new MongoClient(configuration.GetValue<string>("DatabaseSettings: ConnectionString"));
            var database = client.GetDatabase("CatalogDB");

            Products = database.GetCollection<Product>("Products");
            CatalogContextSeed.SeedData(Products);
        }
        public IMongoCollection<Product> Products {  get; }
    }
}
