using Catalog.API.Entities;

namespace Catalog.API.Repositories
{
    //Interfejs koji ce u sustini svaka klasa u repozitorijumima da implementira, jer bez obzira koju bazu ovde koristimo once ce
    //svoju implementaciju ovih funkcija, pa je jednostavno lakse da mozemo da imamo interfejs koji to za nas radi
    public interface IProductRepostories
    {
        //Task je u sustini promise, koristi se za asinhrono pisanje funckija
        Task<IEnumerable<Product>> GetProducts();
        Task<Product> GetProductByID(string id);
        Task<IEnumerable<Product>> GetProductByCategory(string category);
        Task CreateProduct(Product product);
        Task<bool> UpdateProduct(Product product);
        Task<bool> DeleteProduct(string id);
    }
}
